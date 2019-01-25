{
  'targets': [
    {
      'target_name': 'event_loop_native',
      'sources': [
        'src/main.cpp',
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
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
