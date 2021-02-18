class Trie:

    def __init__(self):
        self.trie = {}

    def insert(self, word: str) -> None:
        next = self.trie
        for c in word:
            if c in next:
                next = next[c]
            else:
                next[c] = {}
                next = next[c]
        next['.'] = True

    def search(self, word: str) -> bool:
        next = self.trie
        for c in word:
            if c in next:
                next = next[c]
            else:
                return False
        return '.' in next

    def startsWith(self, prefix: str) -> bool:
        next = self.trie
        for c in prefix:
            if c in next:
                next = next[c]
            else:
                return False
        return True
