// ==UserScript==
// @license MIT
// @name         friend-status-button and luogu link
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  Introduces a button which takes you to the friends standings directly
// @author       fengwei2002
// @match        https://codeforces.com/*/problem/*
// @icon         https://www.google.com/s2/favicons?sz=64&domain=codeforces.com
// @grant        none
// ==/UserScript==

// friends-status-button
(function () {
    'use strict';
    let url = window.location;
    let contestId = url.toString().split("/").filter((x) => {
        if (typeof x !== 'string') { return; }
        const num = Number(x);
        if (Number.isInteger(num)) { return num; }
    })[0];
    let s = url.toString().split("/");
    let id = s[s.length - 1];
    let friendBtn = document.createElement('li');

    friendBtn.innerHTML = `<a href="https://codeforces.com/contest/${contestId}/status/${id}?friends=on" target="_blank">Friends Status</a>`;
    friendBtn.classList.add('friendBtn')
    document.querySelector(".second-level-menu-list").appendChild(friendBtn);
})();

// jump to luogu.com
const pathname = location.pathname

if (/\/problemset\/problem\/(\d*)\/([A-Z][1-9]?)$/.test(pathname)) {
    location.href = `/contest/${RegExp.$1}/problem/${RegExp.$2}`;
}
else if (/\/contest\/(\d*)\/problem\/([A-Z][1-9]?)$/.test(pathname)) {
    let x = $('.header>.title'), y = x.html();
    x.html(`${RegExp.$1 + RegExp.$2} <a href="https://www.luogu.com.cn/problem/CF${RegExp.$1 + RegExp.$2}" target="_blank">${y}</a>`);
}
if (0) {
    var stateObject = {};
    var title = "Wow Title";
    var newUrl = "/my/awesome/url";
    history.pushState(stateObject, title, newUrl);
}

// 