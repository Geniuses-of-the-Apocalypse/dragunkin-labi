from typing import Optional
import re
from collections import Counter


# Уровень 1
def split_words(text: str) -> list[str]:
    return re.findall(r'\w+', text.lower())


# Уровень 2
def count_word_frequencies(words: list[str]) -> dict[str, int]:
    return dict(Counter(words))


# Уровень 3
def top_word(freq: dict[str, int]) -> Optional[str]:
    return max(freq, key=freq.get) if freq else None
