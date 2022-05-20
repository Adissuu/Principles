package Assignment_1.Java;

import java.util.List;

public interface Printable {
    public void print();

    public static void print(List<Printable> obj) {
        print(obj);
    };
}
