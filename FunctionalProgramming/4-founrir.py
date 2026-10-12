from functools import partial

filter_by = lambda key: lambda value: lambda items: [
    item for item in items if item[key] == value
]

filter_by_category = partial(filter_by, "category")

greater_than = lambda threshold: lambda x: x > threshold

if __name__ == "__main__":
    products = [
        {"name": "Яблоко", "category": "фрукты",   "price": 50},
        {"name": "Молоко", "category": "молочное", "price": 80},
        {"name": "Банан",  "category": "фрукты",   "price": 30},
        {"name": "Сыр",    "category": "молочное", "price": 200},
    ]

    fruits = filter_by("category")("фрукты")(products)
    print(" фрукты:", fruits)

    dairy = filter_by_category("молочное")(products)
    print(" молочное:", dairy)

    numbers = [1, 5, 8, 12, 3, 20, 7]
    big = list(filter(greater_than(7), numbers))
    print(" числа > 7:", big)