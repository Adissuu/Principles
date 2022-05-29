
from cmath import pi, sqrt


class Shape():
    newid = 1

    def __init__(self,):
        self.id = Shape.newid
        Shape.newid += 1

    def print(self):
        print(self.id, self.__class__.__name__)

    def perimeter(self):
        return None

    def area(self):
        return None


class Circle(Shape):
    def __init__(self, radius):
        super().__init__()
        self.radius = radius

    def perimeter(self):
        return self.radius * 2 * pi

    def area(self):
        return self.radius * self.radius * pi


class Ellipse(Shape):
    def __init__(self, a, b):
        super().__init__()
        self.a = a
        self.b = b

    def area(self):
        return self.a * self.b * pi

    def eccentricity(self):
        return (sqrt((self.a*self.a) - (self.b*self.b)))


class Rhombus(Shape):
    def __init__(self, dia1, dia2):
        super().__init__()
        self.dia1 = dia1
        self.dia2 = dia2

    def perimeter(self):
        return 2*(self.dia1)/sqrt(2) + 2*(self.dia2)/sqrt(2)

    def area(self):
        return (self.dia1*self.dia2)/2

    def inradius(self):
        return (self.dia1 * self.dia2)/(2 * sqrt((self.dia1*self.dia1)+self.dia2*(self.dia2)))


circle = Circle(5)
square = Circle(7)

reader = open('Assignment_3/readme.txt', 'r')

contents = reader.readlines()

print(contents)
