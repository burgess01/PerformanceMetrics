"""Test file for the eval_primenum file."""

import eval_primenum
import pytest


def test_primeNumBasic():
    ans = eval_primenum.primeNum(22)
    expected = [2, 3, 5, 7, 11, 13, 17, 19]
    assert ans == expected


@pytest.mark.parametrize(
    "maxNum, expected", [(2, [2]), (3, [2, 3]), (14, [2, 3, 5, 7, 11, 13])]
)
def test_multiplePrimeNum(maxNum, expected):
    ans = eval_primenum.primeNum(maxNum)
    assert ans == expected


# pytest benchmark functions
def benchmarkFunc(option):
    for i in range(20):
        option(i)


def test_intMinBenchmark(benchmark):
    benchmark(benchmarkFunc, eval_primenum.primeNum)
