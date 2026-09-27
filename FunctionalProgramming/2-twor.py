from typing import Optional
import re
from collections import Counter


def split_words(text: str) -> list[str]:
    return re.findall(r'\w+', text.lower())


def count_word_frequencies(words: list[str]) -> dict[str, int]:
    return dict(Counter(words))


def top_word(freq: dict[str, int]) -> Optional[str]:
    return max(freq, key=freq.get) if freq else None


print(split_words("Привет, мир! Мир — Python."))

print(count_word_frequencies(split_words("Привет, мир! Мир — Python.")))

print(top_word(count_word_frequencies(split_words("Привет, мир! Мир — Python."))))

print(split_words(""))

print(count_word_frequencies([]))

print(top_word({}))
