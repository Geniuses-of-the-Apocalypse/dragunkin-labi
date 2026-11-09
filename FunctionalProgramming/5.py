from functools import reduce

data = (
    {"name": "Анна", "age": 20, "grade": 4.5},
    {"name": "Борис", "age": 22, "grade": 3.8},
    {"name": "Виктор", "age": 19, "grade": 4.2},
    {"name": "Галина", "age": 21, "grade": 4.9},
    {"name": "Дмитрий", "age": 23, "grade": 3.5},
)

print(tuple(map(lambda s: f"Имя: {s['name']}, Оценка: {s['grade']}", data)))
print(tuple(filter(lambda s: s["grade"] > 4.0, data)))
print(reduce(lambda acc, s: acc + s["age"], filter(lambda s: s["grade"] > 4.0, data), 0) / len(tuple(filter(lambda s: s["grade"] > 4.0, data))))
