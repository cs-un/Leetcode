class FooBar:
    def __init__(self, n):
        self.n = n
        self.cur = 0
        self.lock = threading.Condition()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        with self.lock:
            for i in range(self.n):
                while self.cur != 0:
                    self.lock.wait()
                printFoo()
                self.lock.notify()
                self.cur = 1


    def bar(self, printBar: 'Callable[[], None]') -> None:
        with self.lock:
            for i in range(self.n):
                while self.cur != 1:
                    self.lock.wait()
                printBar()
                self.lock.notify()
                self.cur = 0