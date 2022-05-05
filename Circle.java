public class Circle extends PrintableObject implements Shape {

    double radius;

    public double getRadius() {
        return this.radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public Circle() {
        this.radius = 1;
    }

    public Circle(double r) {
        this.radius = r;
    }

    public static Circle parse(String input) {
        String[] parsed = input.split(",");
        double radius = Double.parseDouble(parsed[1]);
        return new Circle(radius);
    }

    public String toString() {
        return super.getName() + "," + this.getRadius();
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * this.radius;
    }

    @Override
    public double getArea() {
        return Math.PI * this.radius * this.radius;
    }

    @Override
    public String getName() {
        return super.getName().toUpperCase();
    }
}
