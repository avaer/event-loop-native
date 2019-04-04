{
  'targets': [
    {
      'target_name': 'event_loop_native_napi',
      'sources': [
        'src/main.cpp',
      ],
      "include_dirs": [
        "src"
      ],
      'conditions': [
        ['"<!(echo $ANDROID)"=="1"', {
          'defines': ['ANDROID'],
        }],
        ['"<!(echo $LUMIN)"=="1"', {
          'defines': ['LUMIN'],
        }],
      ],
    },
  ],
}
