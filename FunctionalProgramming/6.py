lab 6 зачет 6ec0e83f6738b8d1d603eec3bc9d2fdc1745dee9231f18f3a3bea4a4f8ac07cf

from typing import Any, Callable

def totals(orders):
    def run():
        return map(lambda o: o["total"], orders)
    return run

class Box:
    def __init__(self, v): self.v = v
    def map(self, f): return Box(f(self.v)) if self.v is not None else Box(None)
    def val(self): return self.v

def find(orders, oid):
    def run():
        it = iter(filter(lambda o: o["id"] == oid, orders))
        return Box(next(it, None))
    return run

if __name__ == "__main__":
    data = [{"id": 1, "total": 150.0}, {"id": 2, "total": 300.5}]

    get_totals = totals(data)       
    find_order = find(data, 2)        

    print("1:", tuple(get_totals()))   
    print("2:", find_order().map(lambda o: o["total"]).val())
    print("3:", find(data, 99)().val())



