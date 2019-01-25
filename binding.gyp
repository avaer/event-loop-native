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
        ['"<!(echo $LUMIN)"=="1"', {
          'defines': ['LUMIN'],
        }],
      ],
    },
  ],
}
