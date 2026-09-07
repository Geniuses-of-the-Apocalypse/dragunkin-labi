import csv
from typing import Optional

#1
def parse_csv (data:str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))
#2
def compute_revenue(rows:list[dict]) -> float:
    return sum(int(row["quantity"]) * float(row["price"])
               for row in rows)
#3
def top_item(rows: list[dict])-> Optional[dict]:
    return max(rows, key=lambda row: int(row["quantity"]) * float(row["price"]))
    default = 0

