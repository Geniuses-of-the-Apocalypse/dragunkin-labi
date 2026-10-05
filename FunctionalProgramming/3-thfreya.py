from dataclasses import dataclass
from enum import Enum
from typing import Generic, TypeVar, Union

T = TypeVar("T")
E = TypeVar("E")


class LoadState(Enum):
    LOADING = "loading"
    SUCCESS = "success"
    ERROR = "error"


@dataclass(frozen=True)
class User:
    name: str
    age: int
    email: str


@dataclass(frozen=True)
class Success(Generic[T]):
    value: T


@dataclass(frozen=True)
class Failure(Generic[E]):
    error: E


Result = Union[Success[T], Failure[E]]


def load_users() -> Result[list[User], str]:
    users = [
        User("Daniil", 17, "TheDandy@mail.ri"),
        User("vladimir", 35, "dhshrheksi726@mail.ru"),
    ]
    if not users:
        return Failure("Список людей пустой")
    return Success(users)


result = load_users()

match result:
    case Success(value):
        print("Люди:", value)
    case Failure(error):
        print("тотальный ошибка:", error)
