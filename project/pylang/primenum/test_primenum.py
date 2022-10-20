"""Test file for the eval_primenum file."""

import eval_primenum
import pytest


def test_primeNumBasic():
    ans = eval_primenum.primeNum(22)
    expected = [2, 3, 5, 7, 11, 13, 17, 19]
    assert ans == expected


@pytest.mark.parameterize(
    "maxNum, expected", [(2, [2]), (3, [2, 3]), (14, [2, 3, 5, 7, 11, 13])]
)
def test_multiplePrimeNum(maxNum, expected):
    ans = eval_primenum.primeNum(maxNum)
    assert ans == expected


# TODO: add benchmarking
