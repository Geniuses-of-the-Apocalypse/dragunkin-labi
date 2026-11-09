from functools import partial

FILTER_BY = lambda key: lambda value: lambda items: tuple(
     item for item in items if item.get(key) == value)
FILTER_BY_CATEGORY = partial( lambda key, value, items: tuple(item for item in items if item.get(key) == value), "category")

GREATHER_THAN = lambda threshold: lambda value: value > threshold

if __name__ == "__main__":

    print("фрукты:",  [{"name": "Яблоко", "category": "фрукты", "price": 50},
        {"name": "Молоко", "category": "молочное", "price": 80},
        {"name": "Банан", "category": "фрукты", "price": 30},
        {"name": "Сыр", "category": "молочное", "price": 200},])

    print("\nмолочное:", partial(FILTER_BY_CATEGORY, "молочное")( [{"name": "Яблоко", "category": "фрукты", "price": 50},
        {"name": "Молоко", "category": "молочное", "price": 80},
        {"name": "Банан", "category": "фрукты", "price": 30},
        {"name": "Сыр", "category": "молочное", "price": 200},]))

    print("числа > 7:", tuple(filter( GREATHER_THAN(7), [1, 5, 8, 12, 3, 20, 7])))
