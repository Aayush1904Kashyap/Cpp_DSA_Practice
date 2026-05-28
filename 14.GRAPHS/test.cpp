#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <json/json.h>

using namespace std;

struct Delivery {
    string id;
    double x, y, w, ddl;
};

struct NFZ {
    bool circle;

    double cx, cy, r;

    double x1, y1, x2, y2;

    double ts, te;
};

struct Drone {
    string id;
    double cap;

    double avail = 0.0;

    Json::Value path = Json::arrayValue;
};

inline double DIST(
    double x1,double y1,
    double x2,double y2
) {
    double dx = x1 - x2;
    double dy = y1 - y2;

    return sqrt(dx * dx + dy * dy);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input(
        (istreambuf_iterator<char>(cin)),
        istreambuf_iterator<char>()
    );

    Json::Value root;

    Json::CharReaderBuilder rb;

    string errs;

    istringstream ss(input);

    Json::parseFromStream(
        rb,
        ss,
        &root,
        &errs
    );

    double WX =
        root["map_size"][0].asDouble() * 0.5;

    double WY =
        root["map_size"][1].asDouble() * 0.5;

    vector<Delivery> deliveries;

    for (auto &d : root["deliveries"]) {

        deliveries.push_back({
            d["id"].asString(),
            d["x"].asDouble(),
            d["y"].asDouble(),
            d["weight"].asDouble(),
            d["deadline"].asDouble()
        });
    }

    vector<Drone> drones;

    for (auto &d : root["drones"]) {

        drones.push_back({
            d["id"].asString(),
            d["max_payload"].asDouble()
        });
    }

    sort(
        drones.begin(),
        drones.end(),
        [&](const Drone& a,const Drone& b){
        return a.cap > b.cap;
    });

    sort(
        deliveries.begin(),
        deliveries.end(),
        [&](const Delivery& a,const Delivery& b){

        double da =
            DIST(WX,WY,a.x,a.y);

        double db =
            DIST(WX,WY,b.x,b.y);

        double sa =
            a.ddl - da * 1.5;

        double sb =
            b.ddl - db * 1.5;

        if (fabs(sa - sb) > 1e-9)
            return sa < sb;

        return a.ddl < b.ddl;
    });

    vector<NFZ> nfz;

    Json::Value zones =
        root.get(
            "no_fly_zones",
            Json::Value(Json::arrayValue)
        );

    for (auto &n : zones) {

        NFZ z;

        z.circle =
            n["shape"].asString() == "circle";

        z.ts =
            n["T_start"].asDouble();

        z.te =
            n["T_end"].asDouble();

        if (z.circle) {

            z.cx =
                n["center"][0].asDouble();

            z.cy =
                n["center"][1].asDouble();

            z.r =
                n["radius"].asDouble();

        } else {

            z.x1 =
                n["corners"][0][0].asDouble();

            z.y1 =
                n["corners"][0][1].asDouble();

            z.x2 =
                n["corners"][1][0].asDouble();

            z.y2 =
                n["corners"][1][1].asDouble();

            if (z.x1 > z.x2)
                swap(z.x1, z.x2);

            if (z.y1 > z.y2)
                swap(z.y1, z.y2);
        }

        nfz.push_back(z);
    }



auto blocked =
[&](double ax,double ay,
    double bx,double by,
    double t0)->double {

    double D =
        DIST(ax,ay,bx,by);

    if (D < 1e-9)
        return -1.0;

    double vx =
        (bx - ax) / D;

    double vy =
        (by - ay) / D;

    double waitUntil = -1.0;

    for (auto &z : nfz) {

        double tin = -1e18;
        double tout = 1e18;

        if (z.circle) {

            double dx =
                ax - z.cx;

            double dy =
                ay - z.cy;

            double A =
                vx * vx +
                vy * vy;

            double B =
                2.0 * (
                    vx * dx +
                    vy * dy
                );

            double C =
                dx * dx +
                dy * dy -
                z.r * z.r;

            // EXTRA VALIDATOR SAFETY
            C -= 4.0;

            if (C <= 0.0) {

                tin = 0.0;
                tout = D;

            } else {

                double disc =
                    B * B -
                    4.0 * A * C;

                if (disc < 0.0)
                    continue;

                disc = sqrt(disc);

                double t1 =
                    (-B - disc) /
                    (2.0 * A);

                double t2 =
                    (-B + disc) /
                    (2.0 * A);

                tin =
                    max(
                        0.0,
                        min(t1,t2)
                    );

                tout =
                    min(
                        D,
                        max(t1,t2)
                    );

                // HUGE FIX
                if (tin > D || tout < 0.0)
                    continue;

                tin =
                    max(tin, 0.0);

                tout =
                    min(tout, D);

                if (tin >= tout)
                    continue;
            }

        } else {

            double tmin = 0.0;
            double tmax = D;

            // EXPAND RECTANGLE
            double x1 =
                z.x1 - 2.0;

            double y1 =
                z.y1 - 2.0;

            double x2 =
                z.x2 + 2.0;

            double y2 =
                z.y2 + 2.0;

            if (fabs(vx) < 1e-12) {

                if (
                    ax < x1 ||
                    ax > x2
                )
                    continue;

            } else {

                double tx1 =
                    (x1 - ax) / vx;

                double tx2 =
                    (x2 - ax) / vx;

                if (tx1 > tx2)
                    swap(tx1, tx2);

                tmin =
                    max(tmin, tx1);

                tmax =
                    min(tmax, tx2);
            }

            if (fabs(vy) < 1e-12) {

                if (
                    ay < y1 ||
                    ay > y2
                )
                    continue;

            } else {

                double ty1 =
                    (y1 - ay) / vy;

                double ty2 =
                    (y2 - ay) / vy;

                if (ty1 > ty2)
                    swap(ty1, ty2);

                tmin =
                    max(tmin, ty1);

                tmax =
                    min(tmax, ty2);
            }

            tin = tmin;
            tout = tmax;

            if (tin > D || tout < 0.0)
                continue;

            tin =
                max(tin, 0.0);

            tout =
                min(tout, D);

            if (tin >= tout)
                continue;
        }

        double absIn =
            t0 + tin;

        double absOut =
            t0 + tout;

        // ULTRA STRICT TIME OVERLAP
        if (
            absIn <= z.te + 2.0 &&
            absOut >= z.ts - 2.0
        ) {

            waitUntil =
                max(
                    waitUntil,
                    z.te + 15.0
                );
        }
    }

    return waitUntil;
};

    auto safeStart =
    [&](double ax,double ay,
        double bx,double by,
        double t)->double {

        for (int iter = 0;
             iter < 100;
             iter++) {

            double w =
                blocked(
                    ax,ay,
                    bx,by,
                    t
                );

            if (w < 0.0)
                return t;

            t = w + 5.0;
        }

        return t;
    };

    Json::Value manifest(
        Json::arrayValue
    );

    for (auto &dv : deliveries) {

        int best = -1;

        double bestArr = 1e18;
        double bestRet = 1e18;

        double bestDep = 0.0;
        double bestBackStart = 0.0;
        double bestBack = 0.0;

        double D =
            DIST(
                WX,WY,
                dv.x,dv.y
            );

        for (int i = 0;
             i < (int)drones.size();
             i++) {

            auto &dr =
                drones[i];

            if (dv.w > dr.cap)
                continue;

            double energy =
                D * (1.0 + dv.w)
                + D;

            if (energy > 500.0)
                continue;

            double dep =
                safeStart(
                    WX,WY,
                    dv.x,dv.y,
                    dr.avail
                );

            double arr =
                dep + D;

            if (arr > dv.ddl)
                continue;

            double backStart =
                safeStart(
                    dv.x,dv.y,
                    WX,WY,
                    arr
                );

            double ret =
                backStart + D;

            if (
                arr < bestArr ||
                (
                    fabs(arr - bestArr) < 1e-9 &&
                    ret < bestRet
                )
            ) {

                best =
                    i;

                bestDep =
                    dep;

                bestArr =
                    arr;

                bestBackStart =
                    backStart;

                bestRet =
                    ret;

                bestBack =
                    ret;
            }
        }

        if (best == -1)
            continue;

        auto &dr =
            drones[best];

        Json::Value pickup;

        pickup["x"] = WX;
        pickup["y"] = WY;

        pickup["t"] =
            dr.avail;

        pickup["action"] =
            "PICKUP";

        pickup["delivery_ids"] =
            Json::arrayValue;

        pickup["delivery_ids"]
            .append(dv.id);

        dr.path.append(pickup);

        if (bestDep > dr.avail) {

            Json::Value wait;

            wait["x"] = WX;
            wait["y"] = WY;

            wait["t"] =
                bestDep;

            wait["action"] =
                "WAIT";

            dr.path.append(wait);
        }

        Json::Value deliver;

        deliver["x"] =
            dv.x;

        deliver["y"] =
            dv.y;

        deliver["t"] =
            bestArr;

        deliver["action"] =
            "DELIVER";

        deliver["delivery_id"] =
            dv.id;

        dr.path.append(deliver);

        if (bestBackStart > bestArr) {

            Json::Value wait;

            wait["x"] =
                dv.x;

            wait["y"] =
                dv.y;

            wait["t"] =
                bestBackStart;

            wait["action"] =
                "WAIT";

            dr.path.append(wait);
        }

        Json::Value ret;

        ret["x"] = WX;
        ret["y"] = WY;

        ret["t"] =
            bestBack;

        ret["action"] =
            "RETURN";

        dr.path.append(ret);

        dr.avail =
            bestBack;
    }

    for (auto &d : drones) {

        if (d.path.empty())
            continue;

        Json::Value obj;

        obj["drone_id"] =
            d.id;

        obj["path"] =
            d.path;

        manifest.append(obj);
    }

    Json::Value output;

    output["flight_manifest"] =
        manifest;

    Json::StreamWriterBuilder wb;

    wb["indentation"] = "";

    cout
        << Json::writeString(wb, output)
        << '\n';

    return 0;
}