const path = require('path');

const dlibPath = path.join(__dirname, 'build', 'Release', 'event_loop_native_napi.node');
const {getEventLoopAddress} = require(dlibPath);
const eventLoopAddress = getEventLoopAddress();
eventLoopAddress.getDlibPath = () => dlibPath;

module.exports = eventLoopAddress;
