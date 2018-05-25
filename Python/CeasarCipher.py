class CeasarCipher:
    def __init__(self, shift):
        coder = [None] * 26
        decoder = [None] * 26

        for k in range(26):
            coder[k] = chr((k + shift) % 26 + ord('A'))
            decoder[k] = chr((k - shift) % 26 + ord('A'))

        self._forward = ''.join(coder)
        self._backward = ''.join(decoder)

    def encode(self, message):
        return self._transform(message, self._forward)

    def decode(self, secret):
        return self._transform(secret, self._backward)

    def _transform(self, original, code):
        original = list(original)
        for k in range(len(original)):
            if original[k].isupper():
                j = ord(original[k]) - ord('A')
                original[k] = code[j]

        return ''.join(original)


if __name__ == '__main__':
    cipher = CeasarCipher(3)
    message = 'THE EAGLE IS IN PLAY; MEET AT JOE S.'
    coded = cipher.encode(message)
    print('Secret: ', coded)
    answer = cipher.decode(coded)
    print('Message: ', answer)