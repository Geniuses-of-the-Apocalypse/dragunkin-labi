import csv
from typing import Optional

from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI(title="CSV Revenue API")

# 1
def parse_csv(data: str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))

# 2
def compute_revenue(rows: list[dict]) -> float:
    return sum(map(lambda w: float(w["quantity"]) * float(w["price"]), rows))

# 3
def top_item(rows: list[dict]) -> Optional[dict]:
    return next(
        iter(sorted(rows, key=lambda w: float(w["quantity"]) * float(w["price"]), reverse=True)),
        None,
    )

class CSVRequest(BaseModel):
    data: str


@app.post("/parse")
def parse_endpoint(payload: CSVRequest):
    rows = parse_csv(payload.data)
    return {"rows": rows, "count": len(rows)}


@app.post("/revenue")
def revenue_endpoint(payload: CSVRequest):
    rows = parse_csv(payload.data)
    return {"revenue": compute_revenue(rows)}


@app.post("/top-item")
def top_item_endpoint(payload: CSVRequest):
    rows = parse_csv(payload.data)
    return {"top_item": top_item(rows)}

# функция чистая, не имеет побочных эффектов
# если csv пустое — parse_csv вернёт [], compute_revenue вернёт 0, top_item вернёт None
# Функция parse_csv. Вход str. Выход list[dict] — список словарей, где ключи — названия колонок, значения — строки.
# Функция compute_revenue — вход список, выход выручка по всем строкам.
# Функция top_item — вход list[dict], выход Optional[dict] — словарь с макс прибылью или None.
# тут нет зацикливания, лишних переменных и input/output
# { "data": "date,item,quantity,price\n1931-01-01,cookies,1102.0,1.6\n2022-03-02,cola,523.0,3.2\n2016-09-03,phone,83.0,3.3\n2026-06-04,Milk,2.0,9.2\n2026-09-23,sugar,73.0,3.2" }
