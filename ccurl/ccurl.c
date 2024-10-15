#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(void)
{
  CURL *curl;
  CURLcode res;

  static const char *postthis = "user=daniel&password=monkey123";

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/login.cgi");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postthis);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); /* redirects! */
    curl_easy_setopt(curl, CURLOPT_COOKIEFILE, ""); /* no file */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    else {
      /*
       * After the login POST, we have received the new cookies. Switch
       * over to a GET and ask for the login-protected URL.
       */
      curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/file");
      curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L); /* no more POST */
      res = curl_easy_perform(curl);
      /* Check for errors */
      if(res != CURLE_OK)
        fprintf(stderr, "second curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    }
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}
