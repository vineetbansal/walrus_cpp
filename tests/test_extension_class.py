from walrus.ext import Hello


def test_extension_class():
    hello = Hello()
    assert 'Hello Static Library!' == hello.greet()
