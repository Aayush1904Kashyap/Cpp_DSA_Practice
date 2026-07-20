import sys
from collections import defaultdict

def solve(reference_day, accounts, transactions, merchants, device_activities, location_risks):
    account_map = {acc[0]: acc for acc in accounts}
    merchant_map = {m[0]: m for m in merchants}
    location_map = {lr[0]: lr[1] for lr in location_risks}
    
    device_map = {}
    for _, acc_id, dev_id, first_day in device_activities:
        key = (acc_id, dev_id)
        if key not in device_map or first_day < device_map[key]:
            device_map[key] = first_day

    success_transactions = [t for t in transactions if t[6] == 'SUCCESS']
    
    acc_success_data = defaultdict(lambda: {'sum': 0, 'count': 0})
    for t in success_transactions:
        acc_success_data[t[1]]['sum'] += t[5]
        acc_success_data[t[1]]['count'] += 1
        
    same_day_counts = defaultdict(lambda: defaultdict(int))
    for t in success_transactions:
        same_day_counts[t[1]][t[4]] += 1

    eligible_transactions = []

    for t in transactions:
        t_id, acc_id, m_id, dev_id, loc, t_day, amount, status, input_index = t
        
        if acc_id not in account_map or m_id not in merchant_map or loc not in location_map:
            continue
        if not (1 <= t_day <= reference_day) or amount <= 0 or status != 'SUCCESS':
            continue
            
        risk_score = 0
        
        acc_data = acc_success_data[acc_id]
        if acc_data['count'] > 0:
            avg = acc_data['sum'] / acc_data['count']
            if amount > 2 * avg:
                risk_score += 4
        
        if same_day_counts[acc_id][t_day] >= 3:
            risk_score += 3
            
        if (acc_id, dev_id) not in device_map:
            risk_score += 4
        elif device_map[(acc_id, dev_id)] > t_day:
            risk_score += 3
            
        m_risk = merchant_map[m_id][2]
        if m_risk == 'HIGH': risk_score += 3
        elif m_risk == 'MEDIUM': risk_score += 1
        
        if location_map[loc] >= 4:
            risk_score += 3
            
        if loc != account_map[acc_id][3]:
            risk_score += 2
            
        if risk_score >= 6:
            risk_level = "HIGH" if risk_score >= 10 else "MEDIUM"
            eligible_transactions.append({
                'id': t_id,
                'holder': account_map[acc_id][1],
                'level': risk_level,
                'score': risk_score,
                'amount': amount,
                'index': input_index
            })

    if not eligible_transactions:
        return "NA"

    eligible_transactions.sort(key=lambda x: (
        0 if x['level'] == 'HIGH' else 1,
        -x['score'],
        -x['amount'],
        x['index']
    ))

    return "#".join([f"{t['id']}-{t['holder']}-{t['level']}-{t['score']}" for t in eligible_transactions])

def main():
    # Use sys.stdin for local testing, input format:
    # ref_day
    # acc_count
    # trans_count
    # merc_count
    # dev_count
    # loc_count
    # [acc_lines...]
    # [trans_lines...]
    # [merc_lines...]
    # [dev_lines...]
    # [loc_lines...]
    
    input_data = sys.stdin.read().splitlines()
    if not input_data: return
    
    idx = 0
    reference_day = int(input_data[idx]); idx += 1
    acc_count = int(input_data[idx]); idx += 1
    trans_count = int(input_data[idx]); idx += 1
    merc_count = int(input_data[idx]); idx += 1
    dev_count = int(input_data[idx]); idx += 1
    loc_count = int(input_data[idx]); idx += 1
    
    accounts = []
    for i in range(acc_count):
        parts = input_data[idx].split()
        accounts.append((parts[0], parts[1], parts[2], parts[3], i))
        idx += 1
        
    transactions = []
    for i in range(trans_count):
        parts = input_data[idx].split()
        transactions.append((parts[0], parts[1], parts[2], parts[3], parts[4], int(parts[5]), int(parts[6]), parts[7], i))
        idx += 1
        
    merchants = []
    for i in range(merc_count):
        parts = input_data[idx].split()
        merchants.append((parts[0], parts[1], parts[2]))
        idx += 1
        
    dev_activities = []
    for i in range(dev_count):
        parts = input_data[idx].split()
        dev_activities.append((parts[0], parts[1], parts[2], int(parts[3])))
        idx += 1
        
    loc_risks = []
    for i in range(loc_count):
        parts = input_data[idx].split()
        loc_risks.append((parts[0], int(parts[1])))
        idx += 1
        
    print(solve(reference_day, accounts, transactions, merchants, dev_activities, loc_risks))

if __name__ == "__main__":
    main()