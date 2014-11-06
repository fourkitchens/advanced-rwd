## Extendables

```scss
// Sass
.message {
margin: 1em;
padding: 1em;
font-size: 1.2em;
}
.error {
@extend .message;
color: #060;
}
```

```scss
/* CSS */
.message, .error {
margin: 1em;
padding: 1em;
font-size: 1.2em;
}
.error {
color: #060;
}

```

<p class="fragment">Extendables allow you to build upon a common style.</p>
