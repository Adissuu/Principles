package Java;

public interface NamedObject {

    default String getName() {
        return this.getClass().getSimpleName();
    }
}