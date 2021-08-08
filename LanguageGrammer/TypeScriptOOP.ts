//--------------------------------------------------------- TS 接口和类写法 --------------------------------------------------------------------
interface Person {
    name: string;
    age: number;
}
function printName(person: Person) {
    console.log(person.name);
}

const john = { name: "John", age: 21 };
const mary = { name: "Mary", age: 21, phone: "123-45678" };
printName(john);
printName(mary); // TS 接口语法

interface Comparable<T> {
    compareTo(b: T): number;
}

class MyObject implements Comparable<MyObject> {
    public set age(v: number) {
        this.age = v;
    }
    public get age(): number {
        return this.age;
    }
    compareTo(b: MyObject): number {
        if (this.age === b.age) {
            return 0;
        }
        return this.age > b.age ? 1 : -1;
    }
} // TS 优化后的类写法
