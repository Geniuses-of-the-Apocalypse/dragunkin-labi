import csv
from typing import Optional

CSV_DATA = """\
date,item,quantity,price
1931-01-01,cookies,1102,1.6
2022-03-02,cola,523,3.2
2016-09-03,phone,83,3.3
2026-06-04,Milk,2,9.2
2026-09-23,sugar,73,3.2
"""

# 1
def parse_csv(data: str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))
# 2
def compute_revenue(rows: list[dict]) -> float:
    return sum(int(row["quantity"]) * float(row["price"])
    for row in rows)
# 3
def top_item(rows: list[dict]) -> Optional[dict]:
    return max(rows, key=lambda row: int(row["quantity"]) * float(row["price"]), default=None)

rows = parse_csv(CSV_DATA)

print("Данные: ")
print(rows)
print("\n Доход: ", compute_revenue(rows))
print("\n Максимальная прибыль от товара: ")
print(top_item(rows))
