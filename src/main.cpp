#include <v8.h>
#include <uv.h>
#include <node_api.h>

#ifndef _WIN32
#include <dlfcn.h>
#else
#include <Windows.h>
#endif

namespace eventLoopNative {

napi_value getEventLoopAddress(napi_env env, napi_callback_info args) {
  uv_loop_t *loop;
  napi_get_uv_event_loop(env, &loop);

  napi_value result;
  napi_create_array_with_length(env, 2, &result);
  {
    napi_value n;
    napi_create_uint32(env, 0xFFFFFFFF & ((uintptr_t)loop >> 32), &n);
    napi_set_element(env, result, 0, n);
  }
  {
    napi_value n;
    napi_create_uint32(env, 0xFFFFFFFF & (uintptr_t)loop, &n);
    napi_set_element(env, result, 1, n);
  }

  return result;
}

napi_value Init(napi_env env, napi_value exports) {
  uv_loop_t *loop;
  napi_status status = napi_get_uv_event_loop(env, &loop);
  // uv_async_init(loop, &async, RunInMainThread);
  
  napi_value getEventLoopAddressFn;
  napi_create_function(env, NULL, 0, getEventLoopAddress, NULL, &getEventLoopAddressFn);
  napi_set_named_property(env, exports, "getEventLoopAddress", getEventLoopAddressFn);
  
  return exports;
}

}

#ifndef LUMIN
NAPI_MODULE(NODE_GYP_MODULE_NAME, eventLoopNative::Init)
#else
extern "C" {
  napi_value node_register_module_event_loop_native_napi(napi_env env, napi_value exports) {
    return eventLoopNative::Init(env, exports);
  }
}
#endif

