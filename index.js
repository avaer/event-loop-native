const path = require('path');

const dlibPath = path.join(__dirname, 'build', 'Release', 'event_loop_native_napi.node');
const eventLoopAddress = process.getLoop ?
  process.getLoop()
:
  require(dlibPath).getEventLoopAddress();
eventLoopAddress.getDlibPath = () => dlibPath;

module.exports = eventLoopAddress;
