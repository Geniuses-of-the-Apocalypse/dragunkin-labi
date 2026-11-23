ORDERS = (
    {"id": 1, "total": 1500.0, "status": "completed"},
    {"id": 2, "total": 320.5,  "status": "pending"},
    {"id": 3, "total": 890.0,  "status": "completed"},
    {"id": 4, "total": 45.0,   "status": "cancelled"},
)

print(tuple(map(lambda order: order["total"], ORDERS)))

class OptionalBox:
    def init(self, value):
        self.value = value

    def map(self, func):
        if self.value is None:
            return OptionalBox(None)
        return OptionalBox(func(self.value))

    def repr(self):
        return f"OptionalBox({self.value!r})"

def find_order(orders, order_id):
    return OptionalBox(
        next((order for order in ORDERS if order["id"] == order_id), None)
    )

print(find_order(ORDERS, 2))
print(find_order(ORDERS, 99))