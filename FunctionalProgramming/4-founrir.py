from functools import partial

filter_by = lambda key: lambda value: lambda items: [
     item for item in items if item.get(key) == value
]
filter_by_category = partial( lambda key, value, items: [item for item in items if item.get(key) == value], "category")

greater_than = lambda threshold:  lambda value: value > threshold

items = [{"name": "Яблоко", "category": "фрукты", "price": 50},
        {"name": "Молоко", "category": "молочное", "price": 80},
        {"name": "Банан", "category": "фрукты", "price": 30},
        {"name": "Сыр", "category": "молочное", "price": 200},]

if __name__ == "__main__":


    print("фрукты:", items)

    dairy = partial(filter_by_category, "молочное")
    print(dairy(items))

    over_seven = greater_than(7)
    numbers = [1, 5, 8, 12, 3, 20, 7]
    big = list(filter(over_seven, numbers))
    print("числа > 7:", big)
