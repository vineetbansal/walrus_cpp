import walrus.ext as ext


def test_extension():
    assert 7 == ext.add(3, 4)
    assert 3 == ext.subtract(7, 4)
