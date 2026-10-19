from functools import partial

def filter_by(key, value, items):
    return [item for item in items if item.get(key) == value]

filter_by_category = partial(filter_by, "category")

def greater_than(threshold, value):
    return value > threshold

if __name__ == "__main__":

    fruits = filter_by("category", "фрукты", [
        {"name": "Яблоко", "category": "фрукты", "price": 50},
        {"name": "Молоко", "category": "молочное", "price": 80},
        {"name": "Банан", "category": "фрукты", "price": 30},
        {"name": "Сыр", "category": "молочное", "price": 200},
    ])
    print("фрукты:", fruits)

    dairy = filter_by_category("молочное", [
        {"name": "Яблоко", "category": "фрукты", "price": 50},
        {"name": "Молоко", "category": "молочное", "price": 80},
        {"name": "Банан", "category": "фрукты", "price": 30},
        {"name": "Сыр", "category": "молочное", "price": 200},
    ])
    print("молочное:", dairy)

    numbers = [1, 5, 8, 12, 3, 20, 7]
    big = list(filter(partial(greater_than, 7), numbers))
    print("числа > 7:", big)
