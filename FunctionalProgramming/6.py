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
        self._lazy = _lazy         
    @property
    def value(self):
        if self._lazy is not None:
            self._value = self._lazy()
            self._lazy = None      
        return self._value

    def map(self, func):
        
        def lazy():
            V = self.value
            return None if v is None else func(V)
        return OptionalBox(_lazy=lazy)

    def __iter__(self):
        
        V = self.value
        if V is not None:
            yield V

    def __repr__(self):
        if self._lazy is not None:
            return "OptionalBox(<lazy>)"
        return f"OptionalBox({self._value!r})"


def find_order(orders, order_id):
    return OptionalBox(next((o for o in orders if o["id"] == order_id), None))

print(find_order(ORDERS, 2))
print(find_order(ORDERS, 99))




