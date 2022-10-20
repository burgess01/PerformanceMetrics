"""Test file for the eval_intmin file."""

import eval_intmin
import pytest


def test_minBasic():
    ans = eval_intmin.intMin(2, -2)
    actual = -2
    assert ans == actual


@pytest.mark.parametrize("numOne, numTwo, ans", [(1, 2, 1), (-3, 4, -3), (15, 11, 11)])
def test_multipleIntMin(numOne, numTwo, ans):
    result = eval_intmin.intMin(numOne, numTwo)
    assert result == ans


# pytest benchmark functions
def benchmarkFunc(option):
    for i in range(20):
        option(i, 10)


def test_intMinBenchmark(benchmark):
    benchmark(benchmarkFunc, eval_intmin.intMin)
