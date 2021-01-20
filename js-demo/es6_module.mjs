import { name, another_name, handleDog, handleCat } from './es6_module_utils.mjs';
// import { name as old_name, another_name as new_name } from './es6_module_utils.mjs';
import * as Utils from './es6_module_utils.mjs';

// name = 'new_name'; // 错误，name 是只读的
handleCat.new_name = 'new name'; // 但如果导出的是对象类型，可以在该类型上添加属性。但不建议这么做

console.log(Utils.default);