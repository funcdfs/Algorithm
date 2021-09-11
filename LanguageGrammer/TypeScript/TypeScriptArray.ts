// 数组基本使用 --------------------------------------------------------------------
let daysOfWeek = new Array(); // 开辟数组，
let daysOfWeek2 = []; // 不能对数组类型的变量多次初始化

daysOfWeek = new Array(7); // 开辟定长数组
daysOfWeek = new Array(
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
); // 初始化数组

const fibonacci = []; // {1}
fibonacci[1] = 1; // {2}
fibonacci[2] = 1; // {3}
for (let i = 3; i < 20; i++) {
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]; // {4}
}

let numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
numbers[numbers.length] = 10; // 结尾加上一个数字

numbers.push(11);
numbers.push(12, 13); // 结尾添加多个数字

let value = 0;
for (let i = numbers.length; i >= 0; i--) {
    numbers[i] = numbers[i - 1];
}
numbers[0] = value; // 在数组开头加一个数字 （不常用，但是可以用来模仿数据结构）

numbers.unshift(-2);
numbers.unshift(-4, -3); // unshift 将数字插入到数组的开头，背后逻辑和上面的相同

numbers.pop(); // 删除数组最后面的元素。 push， pop 即可模拟栈

// 时拿出数组开头的元素
// 创建一个新的数组，将所有不是 undefined 的值从原来的数组复制到新的数组中，并且将这个新的数组赋值给我们的数组。

numbers.shift(); // 函数实现，删除数组的第一个元素

// shift 和 unshift 就可以模拟队列

/* 在任意地方添加和删除元素，相比于 cpp 的扩充功能 ------------------------------------------------------------------------------------- */

numbers.splice(5, 3); // 删除数组索引为 5，6,7， 的三个元素

numbers.splice(5, 0, 2, 3, 4); // 不删除元素，从第五个元素开始，加入三个元素

numbers.splice(5, 3, 2, 3, 4); // 先删除三个元素，再添加三个元素，可以用来实现部分元素替换（数量不必相等）

let averageTemp = []; // 实现二维数组的存储
averageTemp[0] = [72, 75, 79, 79, 81, 81];
averageTemp[1] = [81, 79, 75, 75, 73, 73];

// day 1
averageTemp[0] = [];
averageTemp[0][0] = 72;
averageTemp[0][1] = 75;
averageTemp[0][2] = 79;
averageTemp[0][3] = 79;
averageTemp[0][4] = 81;
averageTemp[0][5] = 81;
// day 2
averageTemp[1] = [];
averageTemp[1][0] = 81;
averageTemp[1][1] = 79;
averageTemp[1][2] = 75;
averageTemp[1][3] = 75;
averageTemp[1][4] = 73;
averageTemp[1][5] = 73;

function printMatrix(myMatrix: string | any[]) {
    for (let i = 0; i < myMatrix.length; i++) {
        for (let j = 0; j < myMatrix[i].length; j++) {
            console.log(myMatrix[i][j]);
        }
    }
}

// console.table(averageTemp); // 显示一个更加友好的 二维数组结果

/* 数组的其他成员函数 -------------------------------------------------------------------- */
/*
 * concat

 * join
 * indexOf
 * lastIndexOf
 * map
 * reverse
 * slice
 * sort
 * toString
 *  *         filter
 *  *         every
 *  *         some
 *  *         reduce
 *  *         foreach
 */

// ! concat 连接两个数组
let arrayA = [1, 2, 3];
let arrayB = [4, 5, 6];
let arrayC = arrayA.concat(arrayA, arrayB); // 用逗号分割，连接任意多
// console.log(arrayC);

// ! every 测试数组内的元素是否可以通过，一个函数的判定，全部通过返回 true

const isBelowThreshold = (currentValue: number) => currentValue < 40;

const array1 = [1, 30, 39, 29, 10, 13];

// const isEven = (x) => x % 2 === 0;
// numbers.every(isEven);
// const isEven = x => x % 2 === 0 JS

// console.log(array1.every(isBelowThreshold));
// expected output: true

// ! some() 方法测试数组中是不是至少有1个元素通过了被提供的函数测试。它返回的是一个Boolean类型的值。

const array6 = [1, 2, 3, 4, 5];

// checks whether an element is even
const even = (element: number) => element % 2 === 0;

console.log(array6.some(even));
// expected output: true

// ! reduce 对数组中的每个元素执行一个由您提供的 reducer 函数(升序执行)，将其结果  汇总  为单个返回值。

const arrayReduce = [1, 2, 3, 4];
const reducer = (accumulator: number, currentValue: number) =>
    accumulator + currentValue;

// 1 + 2 + 3 + 4
// console.log(arrayReduce.reduce(reducer));
// expected output: 10

// 5 + 1 + 2 + 3 + 4
// console.log(arrayReduce.reduce(reducer, 5));
// expected output: 15

// ! filter 过滤器，返回数组中满足条件的元素

const words = [
    "spray",
    "limit",
    "elite",
    "exuberant",
    "destruction",
    "present",
];

const result = words.filter((word) => word.length > 6);

// console.log(result);
// expected output: Array ["exuberant", "destruction", "present"]

// ! forEach() 方法对数组的每个元素执行一次给定的函数。，与 for 循环的结果相同

const array2 = ["a", "b", "c"];

// array1.forEach(element => console.log(element));

// expected output: "a"
// expected output: "b"
// expected output: "c"

// !  map() 方法创建一个新数组，其结果是该数组中的每个元素是调用一次提供的函数后的返回值。
const array4 = [1, 4, 9, 16];

// pass a function to map
const map1 = array4.map((x) => x * 2);

// console.log(map1);
// expected output: Array [2, 8, 18, 32]

/* const myMap = numbers.map(isEven);
数组 myMap 里的值是：[false, true, false, true, false, true, false, true,
false, true, false, true, false, true, false]。它保存了传入 map 方法的 isEven
函数的运行结果。这样就很容易知道一个元素是否是偶数。比如，myMap[0]是 false，因为 1
不是偶数；而 myMap[1]是 true，因为 2 是偶数。*/

// !  join() 方法将一个数组（或一个类数组对象）的所有元素连接成一个字符串并返回这个字符串。
// 如果数组只有一个项目，那么将返回该项目而不使用分隔符。

const elements = ["Fire", "Air", "Water"];

// console.log(elements.join());
// expected output: "Fire,Air,Water"

// console.log(elements.join(''));
// expected output: "FireAirWater"

// console.log(elements.join('-'));
// expected output: "Fire-Air-Water"

// !  indexOf()方法返回在数组中可以找到一个给定元素的第一个索引，如果不存在，则返回-1。

const beasts = ["ant", "bison", "camel", "duck", "bison"];

// console.log(beasts.indexOf('bison'));
// expected output: 1

// start from index 2
// console.log(beasts.indexOf('bison', 2));  // indexOf 也可以传入两个参数，返回第 2 个位置
// expected output: 4

// console.log(beasts.indexOf('giraffe'));
// expected output: -1

// ! lastindexOf 用来寻找一个元素在数组中出现的最后一次对应的下标，也可以接收第二个参数
const animals = ["Dodo", "Tiger", "Penguin", "Dodo"];

// console.log(animals.lastIndexOf('Dodo'));
// expected output: 3

const array3 = "123456789";
// console.log(array3.lastIndexOf("9")); // 8
// console.log(array3.lastIndexOf("9", -1)); // -1

// !  reverse() 方法将数组中元素的位置颠倒，并返回该数组。数组的第一个元素会变成最后一个，数组的最后一个元素变成第一个。该方法会改变原数组。
// 相比于 c++ 的 vecctor， JavaScript 原生数组集成了这些方法，使用更加方便

// array1.reverse() // 数组名 + reverse() 即可

// !  slice
// slice() 方法返回一个新的数组对象，这一对象是一个由 begin 和 end 决定的原数组的浅拷贝（包括 begin，不包括end）。原始数组不会被改变。

// arr.slice([begin[, end]])  如果 end 为负数， 则它表示在原数组中的倒数第几个元素结束抽取。
//  slice(-2,-1) 表示抽取了原数组中的倒数第二个元素到最后一个元素（不包含最后一个元素，也就是只有倒数第二个元素）。

const animals2 = ["ant", "bison", "camel", "duck", "elephant"];

// console.log(animals2.slice(2)); // 从下标为 2 的元素开始，之后的所有元素
// expected output: Array ["camel", "duck", "elephant"]

// console.log(animals.slice(2, 4));// 从下标为 2 的元素开始，到下标为 4 的元素
// expected output: Array ["camel", "duck"]

// console.log(animals.slice(1, 5)); // 从下标为 1到下标为5，没有五就到数组末尾
// expected output: Array ["bison", "camel", "duck", "elephant"]

// console.log(animals2.slice(-2)); // 返回倒着数的两个数字
// expected output: Array ["duck", "elephant"]

console.log(animals2.slice(2, -1));
// expected output: Array ["camel", "duck"]

// ! sort函数,需要手写参数
var numbers3 = [4, 2, 5, 1, 3];
numbers3.sort(function (a, b) {
    return a - b;
});
// console.log(numbers3);

// 也可以写成：
var numbers3 = [4, 2, 5, 1, 3];
numbers3.sort((a, b) => a - b);
// console.log(numbers3);

// [1, 2, 3, 4, 5]

// 当排序非 ASCII 字符的字符串（如包含类似 e, é, è, a, ä 等字符的字符串）。一些非英语语言的字符串需要使用 String.localeCompare。这个函数可以将函数排序到正确的顺序。
var items = ["réservé", "premier", "cliché", "communiqué", "café", "adieu"];
items.sort(function (a, b) {
    return a.localeCompare(b);
});

// items is ['adieu', 'café', 'cliché', 'communiqué', 'premier', 'réservé']

// 和 map 结合使用 需要被排序的数组
// var list = ['Delta', 'alpha', 'CHARLIE', 'bravo'];

// // 对需要排序的数字和位置的临时存储
// var mapped = list.map(function(el, i) {
//   return { index: i, value: el.toLowerCase() };
// })

// // 按照多个值排序数组
// mapped.sort(function(a, b) {
//   return +(a.value > b.value) || +(a.value === b.value) - 1;
// });

// // 根据索引得到排序的结果
// var result = mapped.map(function(el){
//   return list[el.index];
// });

/* // ? ES6 新增数组函数 -------------------------------------------------------------------------------*/

/*
 * @@iterator
 * copyWithin
 * entries
 * include
 * find
 * findIndex
 * fill
 * from
 * keys
 * of
 * values
 * for...of
 */

// for...of

for (const n of numbers) {
    // console.log(n % 2 === 0 ? "even" : "odd");
}

//使用 @@iterator 对象

let iterator = numbers[Symbol.iterator]();
for (const n of iterator) {
    // console.log(n);
}

let aEntries = numbers.entries(); // 得到键值对的迭代器 @@iterator，
console.log(aEntries.next().value); // [0, 1] - 位置 0 的值为 1
console.log(aEntries.next().value); // [1, 2] - 位置 1 的值为 2
console.log(aEntries.next().value); // [2, 3] - 位置 2 的值为 3

aEntries = numbers.entries(); // entries 条目
for (const n of aEntries) {
    console.log(n);
}
// 迭代器 @@iterator 和 for of 是相辅相成的

// ! Array.from() 方法从一个类似数组或可迭代对象创建一个新的，浅拷贝的数组实例。
// 用来将各种类型的数据转换为 数组

console.log(Array.from("foo"));
// expected output: Array ["f", "o", "o"]

console.log(Array.from([1, 2, 3], (x) => x + x));
// expected output: Array [2, 4, 6]

// ! 使用 arrayof 创建数组
// let numbers3 = Array.of(1);
// let numbers4 = Array.of(1, 2, 3, 4, 5, 6);

// 等价于

// let numbers3 = [1];
// let numbers4 = [1, 2, 3, 4, 5, 6];

// 可以用这种方法复制，已经存在的数组 （解构操作符，三个点）
// let numbersCopy = Array.of(...numbers4);

// 等价于使用： from

// let numbers2 = Array.from(numbers);

// ! 使用 fill 方法（相当于 cpp 中的 memset 函数）：

// numbersCopy.fill(0);

// numbersCopy.fill(2, 1); 指定开始填充的索引 ，用于部分赋值
let numbersCopy = [0, 2, 3, 4, 5, 6];
numbersCopy.fill(1, 1, 4); // 变为 0,1,1,1,5,6 下标 1 开始， 到 4 结束
// console.log(numbersCopy);

// let ones = Array(6).fill(1); ，在初始化的时候进行赋值操作

// ! copyWithin 复制数组的一部分 arr.copyWithin(target[, start[, end]])

let copyArray = [1, 2, 3, 4, 5, 6];
copyArray.copyWithin(2, 0, 3);

console.log(copyArray); // [ 1, 2, 1, 2, 3, 6 ]

// ! find 和 findIndex 的不同之处在于，find 方法返回第一个满足条件的值，findIndex
// ! 方法则返回这个值在数组里的索引。如果没有满足条件的值，find 会返回 undefined，而 findIndex 返回-1

// let numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15];
// function multipleOf13(element, index, array) {
//     return element % 13 == 0;
// }
// console.log(numbers.find(multipleOf13));  // * 13
// console.log(numbers.findIndex(multipleOf13)); // * 12

// ECMAScript 7 include 方法，存在返回 true， 不存在返回 false

// ! 类型数组 Int32Array; Uint32Array; Float32Array; Float64Array;
// let test = new Int32Array(10).fill(2);

// typescript 中的数组，添加冒号的类型声明
// const friends: Person[]
