def test_addition(self):
    module = load('add')
    self.assertEqual(module.add(1, 2), 1 + 2)


if __name__ == "__main__":
    test_addition()
