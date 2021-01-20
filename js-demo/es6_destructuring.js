/** 数组解构 */
function funcA() {
  {
    const arr = [1, 2, 3];

    const a = arr[0];
    const b = arr[1];
    const c = arr[2];

    console.log(a, b, c);
  }

  // 基本语法
  {
    const [a, b, c] = [1, 2, 3];

    console.log(a, b, c);
  }

  // 不完全捕获
  {
    // 提取除第一个元素外的其他元素
    const [, b1, c1] = [1, 2, 3];
    // 提取除第二个元素外的其他元素
    const [a2, , c2] = [1, 2, 3];
    // 只提取最后一个元素
    const [, , c3] = [1, 2, 3];

    console.log(b1, c1, a2, c2, c3);
  }

  // 捕获 undefined
  {
    const [a, b, c, d] = [1, 2, 3];
    console.log('undefined d:', d);
  }

  // rest 操作符 ...
  {
    const [a, ...b] = [1, 2, 3];

    console.log('rest a: ', a); // output 1
    console.log('rest b:', b);   // output [2, 3]
  }

  // 嵌套数组
  {
    const [a, [inner_1, inner_2], c] = [1, [2, 3], 4];
    // a = 1; inner_1 = 1; inner_2 = 2; c = 3;
    console.log(a, inner_1, inner_2, c);
  }

  // 默认值
  {
    const [a, b, c, d = 4] = [1, 2, 3];
    console.log(a, b, c, d);

    // 不触发默认值 1，null 被正常解构并赋值给 x。
    const [x = 1] = [null];
    console.log('default_value x:', x); // x = null;

    const inner_func = () => 2;
    const [y = inner_func()] = [undefined];

    console.log('default_value y:', y);
  }
}

/** 数组解构 */
function funcB() {
  // 基本语法
  {
    const person = { name: "zhang", sex: "female", age: 18 };
    const {name: name1, sex: sex1, age: age1} = person;
    console.log(name1, sex1, age1);  // name1 = "zhang"; sex1 = "femail"; age1 = 18;
  }
  // 嵌套解构
  {
    const person = { name: "zhang", sex: "female", age: 18, addr: {city: "shenzhen", street: "street1"}};
    const {addr: {city, street: default_street}} = person;

    console.log('city:', city, 'street:', default_street);  // city = "shenzhen"; street = street1;
  }
  // 嵌套数组 + 对象
  {
    const person = {
      name: "zhang",
      sex: "female",
      age: 18,
      more_infos: [
        {
          company: "xxx_company"
        },
        {
          addr: {city: "shenzhen", street: "street1"}
        }
      ]
    };

    const {more_infos: [{ company }, { addr: {city: city1}}]} = person;
    console.log('company:', company, 'city1:', city1); // company = "xxx_company"; city1="shenzhen";
  }
  // 默认值
  {
    const person = { name: "zhang", sex: "female", age: 18 };
    const {interest1="watch moive"} = person;
    console.log('interest1', interest1);  // interest1 = "watch moive"

    const {interest2="watch moive"} = {interest2: null};
    console.log('interest2', interest2);  // interest2 = null
  }
  // 对已声明变量进行解构赋值
  {
    const person = { name: "zhang", sex: "female", age: 18 };
    let age;
    // wrong: { age } = person; 
    ({age} = person);
    console.log(age);

    const me = {
      age: undefined
    };

    ({age: me.age} = person);
    console.log('me', me); // me = {age: 18};
  }
}

/** 其他类型 */
function funcC() {
  // 字符串
  {
    const [a, b, c] = 'lcy';
    console.log(a, b, c); // a = 'l'; b = 'c'; c = 'y';

    const {length : len} = 'lcy';
    console.log('lcy\'s length: ', len);  // len = 3; 
  }
  // 数值、布尔值
  {
    const {toString: number_tostring} = 123;
    console.log(number_tostring === Number.prototype.toString);  // true

    const {toString: bool_tostring} = true;
    console.log(bool_tostring === Boolean.prototype.toString);  // true
  }
}

/** 函数参数解构 */
function funcD() {
  {
    const inner_func = ([x, y, z]) => {
      return x + y + z;
    }

    const sum = inner_func([1, 2, 3]);
    console.log('sum:', sum);
  }

  {
    const inner_func1 = (isOpen, isHook, names, ops) => {
      // ...
    };

    const inner_func2 = (options) => {
      const isOpen = options.isOpen || 'false'; // 使用 || 赋予默认值 
      const isHook = options.isHook || 'true'; 
      const names = options.names || [];
      const ops = options.ops || [];
      // ....
    };

    const inner_func3 = ({isOpen=false, isHook=true, names=[], ops=[]}) => {
      // 马上使用 isOpen、isHook、names、ops 等  
    }

    function requiredParam(param) {
      throw new Error(`Error: Required parameter ${param} is missing`);
    }
    
    const inner_func4 = ({id=requiredParam('id'), isOpen=false, isHook=true, names=[], ops=[]}) => {
      // ...
    }
    
    // inner_func4({});  // 如果不指定 id，inner_func4 将会报错
  }

  // 其他用法
  {
    /** 解构 Map */
    const map = new Map();
    map.set('name', 'zhang');
    map.set('sex', 'female');
    map.set('age', 18);

    // 配合 for...of 进行解构赋值
    for (let [key, value] of map) {
      console.log(key + " is " + value);
    }
    // 仅获取键名
    for (let [key] of map) {
      // ...
    }
    // 仅获取键值
    for (let [,value] of map) {
      // ...
    }

    /** 解构模块  */
    // import { UserUtils, AdminUtils } from 'utils';

    /** 解构函数返回值 */
    function inner_func() {
      return [1, 2, 3];
    }
    
    const [a, b, c] = inner_func();
  }
}

funcA();
funcB();
funcC();
funcD();