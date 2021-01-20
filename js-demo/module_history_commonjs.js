var _name = 'utils';
var _desc = 'utils for dog and cat';

var HandleDog = function() {/* ... */};
var HandleCat = function() {/* ... */};
var GetName = function() { return _name; };

var count = 1;
var moreInfo = {
  innerCount: 1,
};

// module.exports.HandleDog = HandleDog;
// module.exports.HandleCat = HandleCat;
// module.exports.GetName = GetName;


console.log('load module', _name, 'module desc', _desc);

module.exports = {
  count: count,
  moreInfo: moreInfo,
  HandleDog: HandleDog,
  HandleCat: HandleCat,
  GetName: GetName,
}

// console.log('模块信息：', module);
// console.log('exports: ', exports);
// console.log('module.exports === exports', module.exports === exports);
