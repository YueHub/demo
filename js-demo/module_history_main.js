const Utils = require('./es6_module_utils.js');
let count = Utils.count;
count++;
console.log('导出 count，自增后: ', count);
console.log('模块内 count 不受影响: ', Utils.count);

let moreInfo = Utils.moreInfo;
moreInfo.innerCount++;
console.log('导出 inner_count, 自增后: ', moreInfo.innerCount);
console.log('模块内 inner_count 受影响: ', Utils.moreInfo.innerCount);