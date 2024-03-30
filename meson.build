project('eclipse-themes', 'cpp', version: '1.0.0')

sources = [
    'src/main.cpp',
    'src/material/blend/blend.cc',
    'src/material/palettes/core.cc',             
    'src/material/scheme/scheme_fruit_salad.cc',
    'src/material/cam/cam.cc',                               
    'src/material/palettes/tones.cc',            
    'src/material/scheme/scheme_monochrome.cc',
    'src/material/cam/hct.cc',                               
    'src/material/quantize/celebi.cc',           
    'src/material/scheme/scheme_neutral.cc',
    'src/material/cam/hct_solver.cc',                        
    'src/material/quantize/lab.cc',              
    'src/material/scheme/scheme_rainbow.cc',
    'src/material/cam/viewing_conditions.cc',                
    'src/material/quantize/wsmeans.cc',          
    'src/material/scheme/scheme_tonal_spot.cc',
    'src/material/contrast/contrast.cc',                     
    'src/material/quantize/wu.cc',               
    'src/material/scheme/scheme_vibrant.cc',
    'src/material/dislike/dislike.cc',                       
    'src/material/scheme/scheme.cc',             
    'src/material/score/score.cc',
    'src/material/dynamiccolor/dynamic_color.cc',            
    'src/material/scheme/scheme_content.cc',     
    'src/material/temperature/temperature_cache.cc',
    'src/material/dynamiccolor/dynamic_scheme.cc',           
    'src/material/scheme/scheme_expressive.cc',  
    'src/material/utils/utils.cc',
    'src/material/dynamiccolor/material_dynamic_colors.cc',  
    'src/material/scheme/scheme_fidelity.cc',
]

dependencies = [
    dependency('cxxopts')
]

executable('eclipse-themes', sources: sources, dependencies: dependencies, include_directories: include_directories('src'))