public abstract class PrintableObject implements NamedObject, Printable {

    @Override
    public String toString() {
        return "This object's name is " + this.getName() + ".";
    }

    public void print() {
        System.out.println(this.toString());
    }

}
