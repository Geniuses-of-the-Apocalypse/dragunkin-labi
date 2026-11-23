ORDERS = (
    {"id": 1, "total": 1500.0, "status": "completed"},
    {"id": 2, "total": 320.5,  "status": "pending"},
    {"id": 3, "total": 890.0,  "status": "completed"},
    {"id": 4, "total": 45.0,   "status": "cancelled"},
)

print(tuple(map(lambda order: order["total"], ORDERS)))

class OptionalBox:
    def __init__(self, value):
        self.value = value

    def map(self, func):
        if self.value is None:
            return OptionalBox(None)
        return OptionalBox(func(self.value))

    def __repr__(self):
        return f"OptionalBox({self.value!r})"

def find_order(ORDERS, order_id):
    return OptionalBox(
        next((order for order in ORDERS if order["id"] == order_id), None)
    )

print(find_order(ORDERS, 2))
print(find_order(ORDERS, 99))

ORDERS = (
    {"id": 1, "total": 1500.0, "status": "completed"},
    {"id": 2, "total": 320.5,  "status": "pending"},
    {"id": 3, "total": 890.0,  "status": "completed"},
    {"id": 4, "total": 45.0,   "status": "cancelled"},
)

print(tuple(map(lambda order: order["total"], ORDERS)))


class OptionalBox:
    def __init__(self, value=None, _lazy=None):
        self._value = value
        self._lazy = _lazy          # функция без аргументов или None

    @property
    def value(self):
        if self._lazy is not None:
            self._value = self._lazy()
            self._lazy = None       # кэш: вычисляем один раз
        return self._value

    def map(self, func):
        # отложенность: func применится только при чтении .value
        def lazy():
            v = self.value
            return None if v is None else func(v)
        return OptionalBox(_lazy=lazy)

    def __iter__(self):
        # итерируемость: 0 или 1 элемент
        v = self.value
        if v is not None:
            yield v

    def __repr__(self):
        if self._lazy is not None:
            return "OptionalBox(<lazy>)"
        return f"OptionalBox({self._value!r})"


def find_order(orders, order_id):
    return OptionalBox(next((o for o in orders if o["id"] == order_id), None))


# --- демо ---
box = find_order(ORDERS, 2)
print(box)                                   # OptionalBox({'id': 2, ...})
print(box.map(lambda o: o["total"]))         # OptionalBox(<lazy>)
print(box.map(lambda o: o["total"]).value)   # 320.5

chain = box.map(lambda o: o["total"]).map(lambda t: t * 2)
print(chain)                                 # OptionalBox(<lazy>)
print(chain.value)                           # 641.0
print(chain.value)                           # 641.0 (из кэша)

print(list(find_order(ORDERS, 2)))           # [{'id': 2, ...}]
print(list(find_order(ORDERS, 99)))          # []