const path = require('path');

const p = path.join(__dirname, 'build', 'Release', 'event_loop_native_napi.node');
const {getEventLoopAddress, dlclose} = require(p);
const eventLoopAddress = getEventLoopAddress();
dlclose(p);

module.exports = eventLoopAddress;
