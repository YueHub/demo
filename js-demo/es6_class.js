function funcA() {
  /** ES6 以前 */
  {
    const Dog = function() {
      this.name = 'mimi';
      this.sex = 'male';
      this.age = 1;
    }

    const dog1 = Dog();       // dog1 = undefined
    const dog2 = new Dog();   // dog2 = { name: 'mimi', sex: 'male', age: 1 }

    console.log('dog1:', dog1);
    console.log('dog2:', dog2);
    
    // 第一步：继承构造函数
    const Husky = function(name, sex, age, isStupid) {
      Dog.call(this, name, sex, age);
      this.isStupid = true;
    }
    // 第二步：子类的原型指向父类的原型
    Husky.prototype = Object.create(Dog.prototype);
    Husky.prototype.constructor = Husky;  // 修正原型 constructor 的指向

    const husky1 = new Husky('husky', 'male', 2);
    Dog.prototype.sayHi = function() { console.log('wangwang'); }
    console.log('husky1', husky1);
    husky1.sayHi(); // 输出 wangwang，Dog 原型拥有 sayHi() 方法
    console.log('husky1 toString', husky1.toString());  // Object 原型拥有 toString() 方法
  }

  {
    class Dog {
      constructor(name, sex, age) {
        this.name = name;
        this.sex = sex;
        this.age = age;
      }

      sayHi() {
        console.log("wangwang");
      }

      static showPlanet() {
        console.log("汪星球");
      }
    }

    console.log('Dog PropertyNames', Object.getOwnPropertyNames(Dog.prototype));
  }
}

funcA();