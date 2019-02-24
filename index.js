const path = require('path');

const dlibPath = path.join(__dirname, 'build', 'Release', 'event_loop_native_napi.node');
const {getEventLoopAddress, initFunctionAddress} = typeof requireNative === 'undefined' ? require(dlibPath) : requireNative('event_loop_native_napi.node');
const eventLoopAddress = getEventLoopAddress();
eventLoopAddress.getDlibPath = () => dlibPath;
eventLoopAddress.initFunctionAddress = initFunctionAddress;

module.exports = eventLoopAddress;
