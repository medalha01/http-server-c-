#ifndef HTTP_CONSTANTS_H
#define HTTP_CONSTANTS_H

#include <stdio.h>

struct HTTP_CONSTANTS
{
    const char *const HTTP_VERSION = "HTTP/1.1 ";
    const char *const HTTP_CRLF = "\r\n";
    const char *const HTTP_HEADER_DELIMITER = ": ";
    const char *const HTTP_CONTENT_LENGTH = "Content-Length";
    const char *const HTTP_CONTENT_TYPE = "Content-Type";
    const char *const HTTP_CONTENT_TYPE_JSON = "application/json";
    const char *const HTTP_CONTENT_TYPE_TEXT = "text/plain";
    const char *const HTTP_CONTENT_TYPE_HTML = "text/html";
    const char *const HTTP_CONTENT_TYPE_JPEG = "image/jpeg";
    const char *const HTTP_CONTENT_TYPE_PNG = "image/png";
    const char *const HTTP_CONTENT_TYPE_GIF = "image/gif";
    const char *const HTTP_CONTENT_TYPE_OCTET_STREAM = "application/octet-stream";
    const char *const HTTP_CONTENT_TYPE_FORM_URLENCODED = "application/x-www-form-urlencoded";
    const char *const HTTP_CONTENT_TYPE_MULTIPART_FORM_DATA = "multipart/form-data";
    const char *const HTTP_CONTENT_TYPE_TEXT_EVENT_STREAM = "text/event-stream";
    const char *const HTTP_CONTENT_TYPE_APPLICATION_XML = "application/xml";
    const char *const HTTP_CONTENT_TYPE_APPLICATION_XHTML_XML = "application/xhtml+xml";
    const char *const HTTP_OK = "200 OK";
    const char *const HTTP_CREATED = "201 Created";
    const char *const HTTP_ACCEPTED = "202 Accepted";
    const char *const HTTP_NON_AUTHORITATIVE_INFORMATION = "203 Non-Authoritative Information";
    const char *const HTTP_NO_CONTENT = "204 No Content";
    const char *const HTTP_RESET_CONTENT = "205 Reset Content";
    const char *const HTTP_PARTIAL_CONTENT = "206 Partial Content";
    const char *const HTTP_MULTIPLE_CHOICES = "300 Multiple Choices";
    const char *const HTTP_MOVED_PERMANENTLY = "301 Moved Permanently";
    const char *const HTTP_FOUND = "302 Found";
    const char *const HTTP_SEE_OTHER = "303 See Other";
    const char *const HTTP_NOT_MODIFIED = "304 Not Modified";
    const char *const HTTP_USE_PROXY = "305 Use Proxy";
    const char *const HTTP_TEMPORARY_REDIRECT = "307 Temporary Redirect";
    const char *const HTTP_BAD_REQUEST = "400 Bad Request";
    const char *const HTTP_UNAUTHORIZED = "401 Unauthorized";
    const char *const HTTP_PAYMENT_REQUIRED = "402 Payment Required";
    const char *const HTTP_FORBIDDEN = "403 Forbidden";
    const char *const HTTP_NOT_FOUND = "404 Not Found";
    const char *const HTTP_METHOD_NOT_ALLOWED = "405 Method Not Allowed";
    const char *const HTTP_NOT_ACCEPTABLE = "406 Not Acceptable";
    const char *const HTTP_PROXY_AUTHENTICATION_REQUIRED = "407 Proxy Authentication Required";
    const char *const HTTP_REQUEST_TIMEOUT = "408 Request Timeout";
    const char *const HTTP_CONFLICT = "409 Conflict";
    const char *const HTTP_GONE = "410 Gone";
    const char *const HTTP_LENGTH_REQUIRED = "411 Length Required";
    const char *const HTTP_PRECONDITION_FAILED = "412 Precondition Failed";
    const char *const HTTP_PAYLOAD_TOO_LARGE = "413 Payload Too Large";
    const char *const HTTP_URI_TOO_LONG = "414 URI Too Long";
    const char *const HTTP_UNSUPPORTED_MEDIA_TYPE = "415 Unsupported Media Type";
    const char *const HTTP_RANGE_NOT_SATISFIABLE = "416 Range Not Satisfiable";
    const char *const HTTP_EXPECTATION_FAILED = "417 Expectation Failed";
    const char *const HTTP_MISDIRECTED_REQUEST = "421 Misdirected Request";
    const char *const HTTP_UNPROCESSABLE_ENTITY = "422 Unprocessable Entity";
    const char *const HTTP_LOCKED = "423 Locked";
    const char *const HTTP_FAILED_DEPENDENCY = "424 Failed Dependency";
    const char *const HTTP_TOO_EARLY = "425 Too Early";
    const char *const HTTP_UPGRADE_REQUIRED = "426 Upgrade Required";
    const char *const HTTP_PRECONDITION_REQUIRED = "428 Precondition Required";
    const char *const HTTP_TOO_MANY_REQUESTS = "429 Too Many Requests";
    const char *const HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE = "431 Request Header Fields Too Large";
    const char *const HTTP_UNAVAILABLE_FOR_LEGAL_REASONS = "451 Unavailable For Legal Reasons";
    const char *const HTTP_INTERNAL_SERVER_ERROR = "500 Internal Server Error";
    const char *const HTTP_NOT_IMPLEMENTED = "501 Not Implemented";
    const char *const HTTP_BAD_GATEWAY = "502 Bad Gateway";
    const char *const HTTP_SERVICE_UNAVAILABLE = "503 Service Unavailable";
    const char *const HTTP_GATEWAY_TIMEOUT = "504 Gateway Timeout";
    const char *const HTTP_HTTP_VERSION_NOT_SUPPORTED = "505 HTTP Version Not Supported";
    const char *const HTTP_VARIANT_ALSO_NEGOTIATES = "506 Variant Also Negotiates";
    const char *const HTTP_INSUFFICIENT_STORAGE = "507 Insufficient Storage";
    const char *const HTTP_LOOP_DETECTED = "508 Loop Detected";
    const char *const HTTP_NOT_EXTENDED = "510 Not Extended";
    const char *const HTTP_NETWORK_AUTHENTICATION_REQUIRED = "511 Network Authentication Required";
};

#endif // HTTP_CONSTANTS_H
