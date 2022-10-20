"""Test file for the eval_intmin file."""

import intmin
import pytest


def test_minBasic():
    ans = intmin(2, -2)
    actual = -2
    assert ans == actual


@pytest.mark.parameterize("numOne, numTwo, ans", [(1, 2, 1), (-3, 4, -3), (15, 11, 11)])
def test_multipleIntMin(numOne, numTwo, ans):
    result = intmin(numOne, numTwo)
    assert result == ans


# TODO: add benchmarks?
