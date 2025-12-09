import pandas as pd

with open('input.txt', 'r') as f:
    text = f.read().strip()
    
raw_ranges = text.split(',')
parsed_ranges = [r.split('-') for r in raw_ranges]

invalid_ids = []
for start, end in parsed_ranges:
    for num in range(int(start), int(end)+1):
        num = str(num)
        n = len(num)
        first_half = num[:(n//2)]
        second_half = num[(n//2):]
        
        if first_half == second_half:
            invalid_ids.append(int(num))
            
print(sum(invalid_ids))
        
        