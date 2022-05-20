package Assignment_1.Java;

public class Rectangle extends PrintableObject implements Shape {

    double length;
    double width;

    /** Accessors and mutators */
    public double getLength() {
        return this.length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getWidth() {
        return this.width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    /** Constructors */
    public Rectangle() {
        this.length = 1;
        this.width = 1;
    }

    public Rectangle(double l, double w) {
        this.length = l;
        this.width = w;
    }

    public String toString() {
        return super.getName() + "," + this.getLength() + ", "
                + this.getWidth();
    }

    public static Rectangle parse(String input) {
        String[] parsed = input.split(",");
        double length = Double.parseDouble(parsed[1]);
        double width = Double.parseDouble(parsed[2]);
        return new Rectangle(length, width);
    }

    /** Methods overriden */
    @Override
    public double getPerimeter() {
        return (2 * (this.width + this.length));
    }

    @Override
    public double getArea() {
        return (this.width * this.length);
    }

}