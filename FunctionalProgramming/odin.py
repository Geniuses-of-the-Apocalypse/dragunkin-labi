import csv
from typing import Optional

CSV_DATA = """\
date,item,quantity,price
1931-01-01,cookies,1102.0,1.6
2022-03-02,cola,523.0,3.2
2016-09-03,phone,83.0,3.3
2026-06-04,Milk,2.0,9.2
2026-09-23,sugar,73.0,3.2
"""

# 1
def parse_csv(data: str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))
# 2
def compute_revenue(rows: list[dict]) -> float:
    return sum(map(lambda w: float(w["quantity"]) * float(w["price"]), rows))
# 3
def top_item(rows: list[dict]) -> Optional[dict]:
    return next(iter(sorted(rows, key=lambda w: float(w["quantity"]) * float(w["price"]), reverse=True)), None)

rows = parse_csv(CSV_DATA)

print("Данные: ")
print(rows)
print("\n Доход: ", compute_revenue(rows))
print("\n Максимальная прибыль от товара: ")
print(top_item(rows))

#функция чистая не имеет побочных эффектов
# если csv пустое программа упадет, тк флот и инт пустые, если ставим вместо пустых 0 могут быть побочные эффекты
# Функция parse_csv. Входит str. Выходит list[dict] — список словарей, где ключи — названия, а значения — строки.
# Функция compute_revenue -вход список выхож выручка по всем строкам
# Функция top_item входит list[dict]. выходит Optional[dict] - словарь с макс прибылью или none
# тут нету зациклевания, переменных и инут атпут
