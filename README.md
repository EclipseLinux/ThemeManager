# Eclipse Theme Manager

<video autoplay muted loop src="https://user-images.githubusercontent.com/6655696/146014425-8e8e04bc-e646-4cc2-a3e7-97497a3e1b09.mp4" data-canonical-src="https://user-images.githubusercontent.com/6655696/146014425-8e8e04bc-e646-4cc2-a3e7-97497a3e1b09.mp4" class="d-block rounded-bottom-2 width-fit" style="max-width:640px;"></video>

The title is quite clickbait, since it doesn't actually "manage" themes, but generates them based on a specific image.
It's all based purely on the [Material You](https://m3.material.io/) scheme, and generated using their own [scheme generation algorithms](https://github.com/material-foundation/material-color-utilities).

Usage:
```
eclipse-themes <input image> -o [output, defaults to ./theme.json]
```

It's quite unefficient, since it loops through every pixel in the image to do stuff, but it just adds a 1 second overhead, acceptable enough i suppose.
