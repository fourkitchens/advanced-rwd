## Sass Maps

### Only available in Sass 3.3+

```scss
$colors: (
  header: #b06,
  text: #334,
  footer: #666777,
)

p {
  color: map-get($colors, text)
}
```
